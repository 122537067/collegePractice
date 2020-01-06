package com.zhengjiaxin.test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.zhengjiaxin.printer.Pter;
public class test5 {

	public static void main(String[] args) {
		
		ApplicationContext context = new ClassPathXmlApplicationContext("test5.xml");
		ErrorTest test = (ErrorTest)context.getBean("test");
		Pter pter = new Pter();
		pter.setInk("绿色墨盒");
		pter.setPaper("红色纸");
		test.test(pter);
	}

}
