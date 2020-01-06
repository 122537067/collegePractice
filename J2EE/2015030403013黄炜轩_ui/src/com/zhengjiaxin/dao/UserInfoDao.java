package com.zhengjiaxin.dao;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import com.zhengjiaxin.model.UserInfo;

public class UserInfoDao extends BaseDao {
	
	public UserInfoDao() {
	}
	
	/**
	 * 修改密码
	 * @param user
	 * @throws Exception 
	 */
	public void updatePwd(long id,String pwd) throws Exception{
		String sql = "update UserInfo set Password=? where Id=?";
		Map<String,Object> params = new LinkedHashMap<String,Object>();
		params.put("Password", pwd);
		params.put("Id", id);
		
		DbHelper db = this.createDbHelper();
		db.createConnection();
		db.execute(sql, params);
		db.closeConnection();
		
	}

	/**
	 * 根据用户名获取用户对象
	 * @param username
	 * @return
	 */
	public UserInfo getUserInfoByName(String username){
		
		String sql = "select * from UserInfo where Username=?";
		Map<String,Object> params = new LinkedHashMap<String,Object>();
		params.put("UserName", username);
		
		DbHelper db = this.createDbHelper();
		
		UserInfo user = null;
		
		try {
			db.createConnection();
			ResultSet rs = db.query(sql, params);
			
			if(rs.next()){
				user = new UserInfo();
				user.setId(rs.getLong(1));
				user.setUsername(rs.getString(2));
				user.setPassword(rs.getString(3));
			}
			
			db.closeConnection();
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return user;
		
	}
	
	public UserInfo getUserInfoByID(long id){
		
		String sql = "select * from UserInfo where Id=?";
		Map<String,Object> params = new LinkedHashMap<String,Object>();
		params.put("Id", id);
		
		DbHelper db = this.createDbHelper();
		
		UserInfo user = null;
		
		try {
			db.createConnection();
			ResultSet rs = db.query(sql, params);
			
			if(rs.next()){
				user = new UserInfo();
				user.setId(rs.getLong(1));
				user.setUsername(rs.getString(2));
				user.setPassword(rs.getString(3));
			}
			
			db.closeConnection();
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return user;
		
	}
	
	public List<UserInfo> getUserInfos() throws Exception{
		String sql = "select * from UserInfo";
		DbHelper db = this.createDbHelper();
		db.createConnection();
		ResultSet rs = db.query(sql, null);
		
		List<UserInfo> users = new ArrayList<UserInfo>();
		
		while(rs.next()){
			UserInfo user = new UserInfo();
			user.setId(rs.getLong("Id"));
			user.setUsername(rs.getString("Username"));
			user.setPassword(rs.getString("Password"));
			users.add(user);
		}
		
		db.closeConnection();
		
		return users;
	}
	
	public void add(UserInfo model) throws Exception{
		DbHelper db = this.createDbHelper();

		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Username",model.getUsername());
		param.put("Password",model.getPassword());
		db.createConnection();
		
		db.execute("insert into UserInfo(Username,Password) values(?,?)", param);
		
		db.closeConnection();
	}
	
	public void update(UserInfo model) throws Exception{
		DbHelper db = this.createDbHelper();
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Username",model.getUsername());
		param.put("Password",model.getPassword());
		param.put("Id",model.getId());
		
		db.createConnection();
		
		db.execute("update UserInfo set Username=?,Password=? where Id=?", param);
		
		db.closeConnection();
	}
	
	public void delete(long id) throws Exception{
		String sql = "delete from UserInfo where Id=?";
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Id",id);
		
		DbHelper db = this.createDbHelper();
		db.createConnection();
		db.execute(sql, param);
		db.closeConnection();
	}

}
