package com.demo;

import java.sql.ResultSet;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class DbHelperTest {
	
	public static void main(String[] args) throws Exception{
		
		DbHelper db = new DbHelper(Test1.mysql_driver,Test1.mysql_url,Test1.mysql_user,Test1.mysql_pwd);
		
		// LinkedHashMap保持顺序和添加一致
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Id",4);
		param.put("TitleName","科技");
		param.put("Creator","管理员");
		param.put("CreateTime",Test1.getDateString(new Date()));
		
		db.createConnection();
		
		db.execute("insert into FirstLevelTitle values(?,?,?,?)", param);
		
		
		ResultSet rs = db.query("select * from FirstLevelTitle", null);
		while(rs.next()){
			System.out.println(rs.getInt("Id")+"\t"+rs.getString("TitleName"));
		}
		
		db.closeConnection();
		
		System.out.println("ok");
	}

}
