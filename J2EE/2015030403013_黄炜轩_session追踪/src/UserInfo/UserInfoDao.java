package UserInfo;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import ClassInfo.BaseDao;
import ClassInfo.DbHelper;
import RoleInfo.RoleInfo;
import RoleInfo.RoleInfoDao;
import UserInfo.UserInfo;

public class UserInfoDao extends BaseDao {
	
	
	
	public UserInfoDao(HttpServletRequest request){
		super(request);
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
	
	public UserInfo get(long id) throws Exception{
		DbHelper db = this.createDbHelper();
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Id",id);
		
		db.createConnection();
		
		ResultSet rs = db.query("select * from UserInfo where Id=?", param);
		
		UserInfo model = null;
		
		if(rs.next()){
			model = new UserInfo();
			model.setId(rs.getLong(1));
			model.setUsername(rs.getString(2));
			model.setPassword(rs.getString(3));
		}
		
		db.closeConnection();
		
		return model;
	}
	
	public UserInfo getUserByName(String username) throws Exception{
		DbHelper db = this.createDbHelper();
		
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("Username",username);
		
		db.createConnection();
		
		ResultSet rs = db.query("select * from UserInfo where Username=?", param);
		
		UserInfo model = null;
		
		if(rs.next()){
			model = new UserInfo();
			model.setId(rs.getLong(1));
			model.setUsername(rs.getString(2));
			model.setPassword(rs.getString(3));
		}
		
		db.closeConnection();
		
		return model;
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
	
	public List<UserInfo> query(String username) throws Exception{
		String sql = "select * from UserInfo";
		if(username!=null && username.length()>0){
			sql += " where Username like '%"+username+"%'";
		}
		
		DbHelper db = this.createDbHelper();
		
		db.createConnection();
		
		ResultSet rs = db.query(sql, null);
		
		List<UserInfo> list = new ArrayList<UserInfo>();

		while(rs.next()){
			UserInfo model = new UserInfo();
			model.setId(rs.getLong(1));
			model.setUsername(rs.getString(2));
			model.setPassword(rs.getString(3));

			list.add(model);
		}
		
		db.closeConnection();
		
		return list;
	}

public List<RoleInfo> loadPermissions(long userId) throws Exception{
		
		List<RoleInfo> roles = new ArrayList<RoleInfo>();
		
		
		String sql = "select * from RoleInfo where Id in (select RoleInfoId from RoleUser where UserInfoId=?)";
		Map<String,Object> param = new LinkedHashMap<String,Object>();
		param.put("UserInfoId",userId);
		
		DbHelper db = this.createDbHelper();
		
		db.createConnection();
		
		ResultSet rs = db.query(sql, param);
		
		RoleInfoDao roleDao = new RoleInfoDao(this.getDriver(),this.getUrl(),this.getUser(),this.getPwd());
		

		while(rs.next()){
			RoleInfo model = new RoleInfo();
			model.setId(rs.getLong(1));
			model.setCode(rs.getString(2));
			model.setName(rs.getString(3));
			
			model.setFunctions(roleDao.getFunctions(model.getId()));

			roles.add(model);
		}
		
		db.closeConnection();
		
		return roles;
	}
}
