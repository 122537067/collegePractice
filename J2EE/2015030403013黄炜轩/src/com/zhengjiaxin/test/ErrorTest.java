package com.zhengjiaxin.test;

import com.zhengjiaxin.service.PrinterService;
import com.zhengjiaxin.printer.Pter;
public class ErrorTest {
		
	public void test(Pter pter) {
		PrinterService printerService = new PrinterService();
		printerService.print(pter);
	}
}
