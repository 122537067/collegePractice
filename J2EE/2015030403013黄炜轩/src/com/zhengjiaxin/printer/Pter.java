package com.zhengjiaxin.printer;

public class Pter {
	String ink;
	String paper;
	
	public Pter() {
		
	}
	
	public Pter(String ink,String paper) {
		super();
		this.ink = ink;
		this.paper = paper;		
	}
	@Override
	public String toString() {
	    return "Printer [ink=" + ink + ", paper=" + paper + "]";
	}
	
	public String getInk() {
		return ink;
	}

	public void setInk(String ink) {
		this.ink = ink;
	}

	public String getPaper() {
		return paper;
	}

	public void setPaper(String paper) {
		this.paper = paper;
	}
}
