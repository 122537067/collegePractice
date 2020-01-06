package com.sms.dao;

import javax.servlet.http.HttpServletRequest;

public class BaseDao {
	
	private String driver = null;
	private String url = null;
	private String user = null;
	private String pwd = null;
	
	public BaseDao(HttpServletRequest request){
		this.driver = request.getServletContext().getInitParameter("com.mysql.jdbc.Driver");
		this.url = request.getServletContext().getInitParameter("jdbc:mysql://localhost:9003;DatabaseName=sms");
		this.user = request.getServletContext().getInitParameter("root");
		this.pwd = request.getServletContext().getInitParameter("123456");
	}
	
	public DbHelper createDbHelper(){
		return new DbHelper(driver,url,user,pwd);
	}
	
	public String getDriver() {
		return driver;
	}
	public void setDriver(String driver) {
		this.driver = driver;
	}
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}
	public String getUser() {
		return user;
	}
	public void setUser(String user) {
		this.user = user;
	}
	public String getPwd() {
		return pwd;
	}
	public void setPwd(String pwd) {
		this.pwd = pwd;
	}
	
}
