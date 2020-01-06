package com.zhengjiaxin.printer;

import com.zhengjiaxin.ink.Ink;
import com.zhengjiaxin.paper.Paper;
/*
 * 打印机
 * */
public class Print {
	
	private Ink ink;
	private Paper paper;
	public void print() {
		System.out.println("郑佳鑫要用"+ink.getColor()+"在"+paper.getPaperContent()+"上打印");		
	}
	
	public Ink getInk() {
		return ink;
	}
	public Paper getPaper() {
		return paper;
	}
	public void setInk(Ink ink) {
		this.ink = ink;
	}

	public void setPaper(Paper paper) {
		this.paper = paper;
	}
}
