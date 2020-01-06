package com.demo;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

public class FirstLevelTitleDao {
	
	private String driver = null;
	private String url = null;
	private String user = null;
	private String pwd = null;
	
	public FirstLevelTitleDao(HttpServletRequest request){
		this.driver = request.getServletContext().getInitParameter("database_driver");
		this.url = request.getServletContext().getInitParameter("database_url");
		this.user = request.getServletContext().getInitParameter("database_user");
		this.pwd = request.getServletContext().getInitParameter("database_pwd");
	}
	

	public void add(FirstLevelTitle model) throws Exception{
		DbHelper db = new DbHelper(driver,url,user,pwd);
		
		// LinkedHashMap保持顺序和添加一致
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Id",model.getId());
		param.put("TitleName",model.getTitleName());
		param.put("Creator",model.getCreator());
		param.put("CreateTime",model.getCreateTime());
		
		db.createConnection();
		
		db.execute("insert into FirstLevelTitle values(?,?,?,?)", param);
		
		db.closeConnection();
	}
	
	public void update(FirstLevelTitle model) throws Exception{
		DbHelper db = new DbHelper(driver,url,user,pwd);
		
		// LinkedHashMap保持顺序和添加一致
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("TitleName",model.getTitleName());
		param.put("Creator",model.getCreator());
		param.put("CreateTime",model.getCreateTime());
		param.put("Id",model.getId());
		
		db.createConnection();
		
		db.execute("update FirstLevelTitle set TitleName=?,Creator=?,CreateTime=? where Id=?", param);
		
		db.closeConnection();
	}
	
	public FirstLevelTitle get(long id) throws Exception{
		DbHelper db = new DbHelper(driver,url,user,pwd);
		
		// LinkedHashMap保持顺序和添加一致
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Id",id);
		
		db.createConnection();
		
		ResultSet rs = db.query("select * from FirstLevelTitle where Id=?", param);
		
		FirstLevelTitle model = null;
		
		if(rs.next()){
			model = new FirstLevelTitle();
			model.setId(rs.getLong(1));
			model.setTitleName(rs.getString(2));
			model.setCreator(rs.getString(3));
			model.setCreateTime(rs.getDate(4));
		}
		
		db.closeConnection();
		
		return model;
	}
	
	public List<FirstLevelTitle> query(String sqlWhere,Map<String,Object> param) throws Exception{
		String sql = "select * from FirstLevelTitle";
		if(sqlWhere!=null && param!=null){
			sql += sqlWhere;
		}
		
		DbHelper db = new DbHelper(driver,url,user,pwd);
		
		db.createConnection();
		
		ResultSet rs = db.query(sql, param);
		
		List<FirstLevelTitle> list = new ArrayList<FirstLevelTitle>();

		while(rs.next()){
			FirstLevelTitle model = new FirstLevelTitle();
			model.setId(rs.getLong(1));
			model.setTitleName(rs.getString(2));
			model.setCreator(rs.getString(3));
			model.setCreateTime(rs.getDate(4));
			
			list.add(model);
		}
		
		db.closeConnection();
		
		return list;
	}

}
