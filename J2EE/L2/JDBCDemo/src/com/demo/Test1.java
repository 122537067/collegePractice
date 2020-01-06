package com.demo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Test1 {
	
	public static String sqlserver_driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
	public static String sqlserver_url = "jdbc:sqlserver://127.0.0.1:1433; DatabaseName=TestDb";
	
	public static final String sqlserver_user = "sa";
	public static final String sqlserver_pwd = "tenran";
	
	public static String mysql_driver = "com.mysql.jdbc.Driver";
	public static String mysql_url = "jdbc:mysql://localhost:3306/Quick.Test";
	
	public static final String mysql_user = "root";
	public static final String mysql_pwd = "123456";
	
	public static void main(String[] args) throws Exception{
		
		//testSqlServer();
		
		//testMySql();
		
		//testSqlServer2();
		
		//testMySql2();
		
		testMySql3();
		
		System.out.println("ok");
		
	}
	
	private static void testSqlServer() throws Exception {
		String sql = "insert into FirstLevelTitle values(1,'军事','网管',getdate())";

		Class.forName(sqlserver_driver);
		Connection con = DriverManager.getConnection(sqlserver_url,sqlserver_user,sqlserver_pwd);
		Statement statement = con.createStatement();
		statement.executeUpdate(sql);
		statement.close();
		con.close();
	}
	
	private static void testSqlServer2() throws Exception {
		String sql = "insert into FirstLevelTitle values(?,?,?,?)";

		Class.forName(sqlserver_driver);
		Connection con = DriverManager.getConnection(sqlserver_url,sqlserver_user,sqlserver_pwd);
		PreparedStatement statement = con.prepareStatement(sql);
		statement.setInt(1, 2);
		statement.setString(2, "财经");
		statement.setString(3, "管理员");
		statement.setString(4, getDateString(new Date()));
		statement.executeUpdate();
		statement.close();
		con.close();
	}
	
	private static void testMySql() throws Exception {
		String sql = "insert into FirstLevelTitle values(1,'军事','网管','2018-02-01 00:00:00')";
		Class.forName(mysql_driver);
		Connection con = DriverManager.getConnection(mysql_url,mysql_user,mysql_pwd);
		Statement statement = con.createStatement();
		statement.executeUpdate(sql);
		statement.close();
		con.close();
	}
	
	private static void testMySql2() throws Exception {
		String sql = "insert into FirstLevelTitle values(?,?,?,?)";
		Class.forName(mysql_driver);
		Connection con = DriverManager.getConnection(mysql_url,mysql_user,mysql_pwd);
		PreparedStatement statement = con.prepareStatement(sql);
		statement.setInt(1, 2);
		statement.setString(2, "财经");
		statement.setString(3, "管理员");
		statement.setString(4, getDateString(new Date()));
		statement.executeUpdate();
		
		statement.close();
		con.close();
	}
	
	private static void testMySql3() throws Exception {
		String sql = "update FirstLevelTitle set TitleName=? where Id=?";
		Class.forName(mysql_driver);
		Connection con = DriverManager.getConnection(mysql_url,mysql_user,mysql_pwd);
		PreparedStatement statement = con.prepareStatement(sql);
		
		statement.setString(1, "财经2");
		statement.setInt(2, 2);

		statement.executeUpdate();
		
		statement.close();
		con.close();
	}
	
	public static String getDateString(Date date){
		SimpleDateFormat sf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		return sf.format(date);
	}

}
