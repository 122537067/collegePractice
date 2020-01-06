package com.zhengjiaxin.service;

import com.zhengjiaxin.dao.PrinterDao;
import com.zhengjiaxin.printer.Pter;


public class PrinterService {
	private PrinterDao dao;

	public PrinterDao getDao() {
		return dao;
	}

	public void setDao(PrinterDao dao) {
		this.dao = dao;
	}
	
	public void print(Pter pter) {
		if (!pter.getInk().equals("红色墨盒")||!pter.getPaper().equals("A4纸")) {
			System.out.println("不是绿色墨盒或者A4纸不予许打印");
			return;
		}
		dao.print(pter);
	}
}
