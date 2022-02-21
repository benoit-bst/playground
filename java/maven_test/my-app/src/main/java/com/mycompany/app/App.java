package com.mycompany.app;

// logging
import org.apache.log4j.BasicConfigurator;  
import org.apache.log4j.LogManager;  
import org.apache.log4j.Logger;

import org.apache.commons.collections4.list.TreeList;

import com.mycompany.app.utils.Utils;

/**
 * TreeList test
 */
public class App 
{
    private static final Logger logger = LogManager.getLogger(App.class); 

    private static void treeList()
    {
        logger.info("Tree List features");
        TreeList<String> tree_list = new TreeList<String>();
        tree_list.add("1");
        tree_list.add("2");
        tree_list.add("3");
        for (int i = 0; i < tree_list.size(); i++) {
            System.out.println(tree_list.get(i));
        }
        logger.info("static value " + Utils.STATIC_VALUE);
    }

    public static void main(final String[] args)
    {
        BasicConfigurator.configure();
        logger.info("starting test");
        treeList();
    }

}
