# -*- coding: utf-8 -*-
# Pretty-printers std::string.

import gdb
import itertools
import re

def parseAndEval(exp):
    if not gdb.VERSION.startswith("7.0.1"):
      return gdb.parse_and_eval(exp)
    # Work around non-existing gdb.parse_and_eval as in released 7.0
    gdb.execute("set logging redirect on")
    gdb.execute("set logging on")
    gdb.execute("print %s" % exp)
    gdb.execute("set logging off")
    return gdb.history(0)

def typedPointer(gdbValue):
    return "(( const "+str(gdbValue.type).replace("&","") + " *)"+str(gdbValue.address)+")"
    # without "const", it may freeze gdb, at least on debian squeeze's gdb version

class st_printer:
    "Print a stTest"

    def __init__(self, val):
      self.val = val

    def to_string(self):
      val1 = str(self.val['val1'])
      val2 = str(self.val['val2'])
      out = val1 + " - " + val2
      return out

    def display_hint(self):
      return 'std::string'

class complexPrinter:

    def __init__(self, val):
      self.val = val

    def to_string(self):
      out = str(self.val['_M_value'])
      out = out.replace(" * I","i");
      out = out.replace("+ -","- ");
      return out

    def display_hint(self):
      return 'std::complex'

def register_tests_printers (obj):
    if obj == None:
        obj = gdb
    obj.pretty_printers.append (lookup_function)

def lookup_function (val):
    "Look-up and return a pretty-printer that can print val."

    # Get the type.
    type = val.type;

    # If it points to a reference, get the reference.
    if type.code == gdb.TYPE_CODE_REF:
        type = type.target ()

    # Get the unqualified type, stripped of typedefs.
    type = type.unqualified ().strip_typedefs ()

    # Get the type name.
    typename = type.tag
    if typename == None:
        return None

    # Iterate over local dictionary of types to determine
    # if a printer is registered for that type.  Return an
    # instantiation of the printer if found.
    for function in pretty_printers_dict:
        if function.search (typename):
            return pretty_printers_dict[function] (val)

    # Cannot find a pretty printer.  Return None.
    return None

def build_dictionary ():
    pretty_printers_dict[re.compile('^stTest')] = lambda val: st_printer(val)
    pretty_printers_dict[re.compile('^std::complex')] = lambda val: complexPrinter(val)

pretty_printers_dict = {}

build_dictionary ()