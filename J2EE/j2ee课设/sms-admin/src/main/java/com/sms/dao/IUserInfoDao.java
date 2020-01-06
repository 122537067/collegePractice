package com.sms.dao;

import java.util.List;

import com.sms.model.UserInfo;

public interface IUserInfoDao {
    /**
     * 新增用戶
     * @param user
     * @return
     * @throws Exception
     */
    public int insertUser(UserInfo user) throws Exception;
    
    /**
     * 修改用戶
     * @param user
     * @param id
     * @return
     * @throws Exception
     */
    public int updateUser (UserInfo user) throws Exception;
    
     /**
      * 刪除用戶
      * @param id
      * @return
      * @throws Exception
      */
    public int deleteUser(int id) throws Exception;
    
    /**
     * 根据id查询用户信息
     * @param id
     * @return
     * @throws Exception
     */
    public UserInfo selectUserById(long id) throws Exception;
    
     /**
      * 查询所有的用户信息
      * @return
      * @throws Exception
      */
    public List<UserInfo> selectAllUser() throws Exception;
    
    public UserInfo selectUserByUsername(String username);
}