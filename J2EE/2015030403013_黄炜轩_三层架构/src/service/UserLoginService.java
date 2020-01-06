package service;

import java.util.ArrayList;
import java.util.List;

import UserWeb.userlogin;
import dao.UserInfoDao;
import model.UserInfo;

public class UserLoginService {

	public UserLoginService() {
		super();
	}
	
	public boolean Login(String username,String pwd) {
		try {
			UserInfo user = new UserInfoDao().getUserByName(username);
			
			if(user==null){
				return false;
			}
				
			if(!user.getPassword().equals(pwd)){
				return true;
			}
		} catch (Exception e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return false;
	}
	//失败！！！！
	public List<UserInfo> SetRoles(String username) throws Exception{
		
		UserInfo user = new UserInfoDao().getUserByName(username);
		UserInfoDao userDao = new UserInfoDao();
		user.setRoles(userDao.loadPermissions(user.getId()));
		List<UserInfo> aList= (List<UserInfo>) new UserInfoDao().getUserByName(username);
		return aList;
	}
}
