"""
    ipscan
"""
from __future__ import annotations
import os

def check_ping(ip):
    response = os.system("ping -c 1 " + ip)
    # and then check the response...
    if response == 0:
        pingstatus = "Network Active"
    else:
        pingstatus = "Network Error"

    return pingstatus

def scanner1(start: str, end: str) -> None:

    # retreive slot
    s = start.split('.')
    e = end.split('.')

    # O(N^4) -> N = 255 (4294967296)
    for idx_0 in range(int(s[0]), int(e[0]) + 1):
        for idx_1 in range(int(s[1]), int(e[1]) + 1):
            for idx_2 in range(int(s[2]), int(e[2]) + 1):
                for idx_3 in range(int(s[3]), int(e[3]) + 1):
                    current_ip = str(idx_0) + '.' + str(idx_1) + '.' + str(idx_2) + '.' + str(idx_3)
                    print("IP: " + current_ip + " - " + check_ping(current_ip))



if __name__ == "__main__":

    start = '0.0.0.0'
    end = '255.255.255.255'
    # scanner1(start, end)

    start = '254.255.0.0'
    end = '254.255.0.15'
    scanner1(start, end)
