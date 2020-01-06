package com.test;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class Test2 {
	
	private static final String db_driver = "com.mysql.jdbc.Driver";
	private static final String url = "jdbc:mysql://localhost:3306/DbTest";
	private static final String username = "root";
	private static final String pwd = "123456";
	
	public static void main(String[] args) throws Exception{
		
		DbHelper helper = new DbHelper(db_driver,url,username,pwd);
		helper.createConnection();
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Name", "一个学生");
		param.put("Age", 24);
		
		
		helper.execute("insert into StudentInfo(Name,Age) values(?,?)", param);
		helper.closeConnection();
		
		System.out.println("Ok");
	}

}
