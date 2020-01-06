package com.zhengjiaxin.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.zhengjiaxin.printer.Print;

public class PrintTest {

	public static void main(String[] args) {
		ApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
        Print printer = (Print)context.getBean("printer");
        printer.print();
	}

}
