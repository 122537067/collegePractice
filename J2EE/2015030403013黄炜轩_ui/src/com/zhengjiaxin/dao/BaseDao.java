package com.zhengjiaxin.dao;

import java.io.InputStream;

import org.dom4j.Document;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;

public class BaseDao {
	
	private String driver = null;
	private String url = null;
	private String user = null;
	private String pwd = null;
	
	public BaseDao(){
		try{
			InputStream is = this.getClass().getResourceAsStream("/dbconfig.xml");
			Document doc = new SAXReader().read(is);
			Element root = doc.getRootElement();
			
			driver = root.element("driver").getText();
			url = root.element("url").getText();
			user = root.element("user").getText();
			pwd = root.element("pwd").getText();
		
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}
	
	public DbHelper createDbHelper(){
		return new DbHelper(driver,url,user,pwd);
	}
	
	
}
