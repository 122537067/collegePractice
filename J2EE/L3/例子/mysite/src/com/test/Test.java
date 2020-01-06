package com.test;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Test {
	
	public static void main(String[] args){
		Date date = new Date();
		SimpleDateFormat sf = new SimpleDateFormat("yyyy年MM月dd日 HH点mm分ss秒");
		String currentDate = sf.format(date);
	}

}
