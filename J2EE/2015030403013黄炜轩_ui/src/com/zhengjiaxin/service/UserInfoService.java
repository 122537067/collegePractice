package com.zhengjiaxin.service;

import java.util.List;

import org.json.JSONObject;

import com.zhengjiaxin.dao.UserInfoDao;
import com.zhengjiaxin.model.UserInfo;

public class UserInfoService {
	
	public UserInfoService(){
		
	}
	
	/**
	 * 处理用户登录的逻辑，成功登录返回用户信息，否则返回null
	 * @param username
	 * @param pwd
	 * @return
	 */
	public UserInfo login(String username,String pwd){
		UserInfo user = new UserInfoDao().getUserInfoByName(username);
		if(user==null) return null;
		
		if(user.getPassword().equals(pwd)) return user;
		
		return null;
		
	}
	
	public UserInfo getUserInfoByID(long id){
		return new UserInfoDao().getUserInfoByID(id);
	}
	
	public void updatePwd(UserInfo user) throws Exception{
		new UserInfoDao().updatePwd(user.getId(), user.getPassword());
	}
	
	public String getUserInfoJsonData() throws Exception{
		List<UserInfo> users = new UserInfoDao().getUserInfos();
		String jsonData = JSONObject.valueToString(users);
		return jsonData;
	}
	
	public void addUserInfo(UserInfo user) throws Exception{
		new UserInfoDao().add(user);
	}
	
	public void updateUserInfo(UserInfo user) throws Exception{
		new UserInfoDao().update(user);
	}
	
	public void deleteUserInfo(long id) throws Exception{
		new UserInfoDao().delete(id);
	}

}
