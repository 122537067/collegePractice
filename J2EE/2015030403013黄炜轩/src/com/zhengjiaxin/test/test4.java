package com.zhengjiaxin.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.zhengjiaxin.service.PrinterService;
import com.zhengjiaxin.printer.Pter;

public class test4 {

	public static void main(String[] args) {
		ApplicationContext context = new ClassPathXmlApplicationContext("test4.xml");
		PrinterService printerService =(PrinterService)context.getBean("service");
		printerService.print(new Pter("红色墨盒","A4纸"));

	}

}
