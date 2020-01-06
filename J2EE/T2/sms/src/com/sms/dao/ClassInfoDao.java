package com.sms.dao;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import com.sms.model.ClassInfo;

public class ClassInfoDao extends SQLServerDao
{
	//读取数据库信息
	public List<ClassInfo> printTable(String sqlWhere,Map<String,Object> param) throws Exception
	{
		String sql = "select * from T_class";
		
		if(sqlWhere!=null && param != null)
		{
			sql += sqlWhere;
		}
		
		DbHelper db = new DbHelper(db_driver,url,username,pwd);
		db.createConnection();
		ResultSet rs = db.query(sql, param);
		List<ClassInfo> list = new ArrayList<ClassInfo>();

		while (rs.next())
		{
			ClassInfo model = new ClassInfo();
			model.setID(rs.getInt(1));
			model.setNo(rs.getString(2));
			model.setName(rs.getString(3));
			
			list.add(model);
		}
		
		db.closeConnection();
		return list;
	}
	
	//增加
	public void add(ClassInfo cclass) throws Exception
	{
		String sql = "insert into T_class(No,Name) values(?,?)";
		
		DbHelper db = new DbHelper(db_driver,url,username,pwd);
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("No", cclass.getNo());
		param.put("Name", cclass.getName());
		
		db.createConnection();
		db.execute(sql, param);
		db.closeConnection();
	}
	
	//删除
	public void delete(ClassInfo cclass) throws Exception
	{
		String sql = "delete from T_Class where ID=?";
		
		DbHelper db = new DbHelper(db_driver,url,username,pwd);
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("ID", cclass.getID());
		
		db.createConnection();
		db.execute(sql, param);
		db.closeConnection();
	}
	
	//更新
	public void update(ClassInfo cclass) throws Exception
	{
		DbHelper db = new DbHelper(db_driver, url, username, pwd);
		Map<String, Object> param = new LinkedHashMap<String,Object>();
		String sql = "update T_Class set No=?,Name=? where ID=?";
		
		param.put("No", cclass.getNo());
		param.put("Name", cclass.getName());
		param.put("ID", cclass.getID());
		db.createConnection();
		db.execute(sql, param);
		db.closeConnection();
	}
	
	//通过ID找到课室信息
	public ClassInfo Get_Class(int id) throws Exception{
		DbHelper db = new DbHelper(db_driver,url,username,pwd);

		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("ID",id);
		
		db.createConnection();
		
		ResultSet rs = db.query("select * from T_Class where ID=?", param);
		

		ClassInfo model = null;
		
		if(rs.next()){
			model = new ClassInfo();
			model.setID(rs.getInt(1));
			model.setNo(rs.getString(2));
			model.setName(rs.getString(3));
		}
		
		db.closeConnection();
		
		return model;
	}

}
