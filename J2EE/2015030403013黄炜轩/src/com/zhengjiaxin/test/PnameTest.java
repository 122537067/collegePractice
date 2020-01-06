package com.zhengjiaxin.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.zhengjiaxin.printer.Pter;
public class PnameTest {
	public static void main(String[] args) {
		ApplicationContext context = new ClassPathXmlApplicationContext("Pname.xml");
        Pter pter= (Pter)context.getBean("pter");
        System.out.println(pter.toString());
	}
}
