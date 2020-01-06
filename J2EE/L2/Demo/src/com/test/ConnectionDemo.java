package com.test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class ConnectionDemo {
	
	private static final String db_driver = "com.mysql.jdbc.Driver";
	private static final String url = "jdbc:mysql://localhost:3306/DbTest";
	private static final String username = "root";
	private static final String pwd = "123456";
	
	public static void main(String[] ars) throws  Exception{
		
		updateName("王五","王老二");
		
		System.out.println("ok");
		
	}
	
	private static void updateName(String oldName,String newName) throws Exception{
		Class.forName(db_driver);
		
		Connection con = DriverManager.getConnection(url,username,pwd);
		
		
		String sql = "update StudentInfo set Name=? where Name=?";
		
		PreparedStatement pstmt = con.prepareStatement(sql);
		
		pstmt.setString(1, newName);
		pstmt.setString(2, oldName);
		
		pstmt.execute();
		
		
		con.close();
	}

}
