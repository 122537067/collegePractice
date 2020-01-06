package com.test;

import java.sql.ResultSet;
import java.util.LinkedHashMap;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;


public class UserInfoDao {
	
	private String driver = null;
	private String url = null;
	private String user = null;
	private String pwd = null;
	
	public UserInfoDao(HttpServletRequest request)
	{
		this.driver = request.getServletContext().getInitParameter("database_driver");
		this.url = request.getServletContext().getInitParameter("database_url");
		this.user = request.getServletContext().getInitParameter("database_user");
		this.pwd = request.getServletContext().getInitParameter("database_pwd");
		
		System.out.println("driver="+driver);
		System.out.println("url="+url);
		System.out.println("user="+user);
		System.out.println("pwd="+pwd);
	}
	
	public boolean login(String username,String pwd) throws Exception{
		DbHelper db = new DbHelper(driver,url,user,this.pwd);
		String sql = "select * from UserInfo where Username=? and Password=?";
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Username", username);
		param.put("Password", pwd);
		
		db.createConnection();
		ResultSet rs = db.query(sql, param);
		
		if(rs.next()){
			db.closeConnection();
			return true;
		}
		
		db.closeConnection();
		return false;
	}

}
