package com.zhengjiaxin.dao;

import com.zhengjiaxin.printer.Pter;
public class PrinterDao {
	public void print(Pter pter) {
		System.out.println("郑佳鑫使用"+pter.getInk()+"打印"+pter.getPaper());
	}
}
