package com.mysms.iservice;

import com.mysms.model.UserInfo;

import java.util.List;

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
	public UserInfo login(String username, String password)  throws Exception;

	/**
	 * 新增用户
	 */
	public void insertUser(UserInfo user) throws  Exception;

	public void deleteUser(int id) throws Exception;

	public void updateUser(UserInfo user) throws Exception;

	public void updatepwd(int userId, String newpwd) throws Exception;

	public UserInfo getUserById(int id) throws Exception;

	public UserInfo getUserByUsername(String username) throws Exception;
}
