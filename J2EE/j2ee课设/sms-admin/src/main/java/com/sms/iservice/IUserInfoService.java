package com.sms.iservice;

import java.util.List;

import com.sms.model.UserInfo;

public interface IUserInfoService {
	
	/**
	 * 获取所有用户信息
	 * @return
	 * @throws Exception 
	 */
	public List<UserInfo> getAllUsers() throws Exception;
	
	/**
	 * 用户登录
	 * @param username
	 * @param password
	 */
	public UserInfo login(String username,String password)  throws Exception;
	
	public void updatepwd(long userId,String newpwd) throws Exception;
}
