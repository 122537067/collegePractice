package com.mysms.dao;

import com.mysms.model.ClassInfo;

import java.util.List;

public interface IClassInfoDao {
    /**
     * 新增班级
     * @param
     * @return
     * @throws Exception
     */
    public int insertClassInfo(ClassInfo model) throws Exception;
    
    /**
     * 修改班级
     * @param
     * @param
     * @return
     * @throws Exception
     */
    public int updateClassInfo(ClassInfo model) throws Exception;
    
     /**
      * 刪除班级
      * @param id
      * @return
      * @throws Exception
      */
    public int deleteClassInfo(int id) throws Exception;
    
    /**
     * 根据id查询班级信息
     * @param id
     * @return
     * @throws Exception
     */
    public ClassInfo selectClassInfoById(int id) throws Exception;
    
     /**
      * 查询所有的班级信息
      * @return
      * @throws Exception
      */
    public List<ClassInfo> selectAllClassInfo() throws Exception;
}