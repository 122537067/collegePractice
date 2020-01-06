package com.mysms.dao;

import com.mysms.model.StuInfo;

import java.util.List;

public interface IStuInfoDao {

    /**
     * 新增学生
     * @param
     * @return
     * @throws Exception
     */
    public int insertStuInfo(StuInfo model) throws Exception;

    /**
     * 修改学生
     * @param
     * @param
     * @return
     * @throws Exception
     */
    public int updateStuInfo(StuInfo model) throws Exception;

    /**
     * 刪除学生
     * @param id
     * @return
     * @throws Exception
     */
    public int deleteStuInfo(int id) throws Exception;

    /**
     * 根据id查询学生信息
     * @param id
     * @return
     * @throws Exception
     */
    public StuInfo selectStuInfoById(int id) throws Exception;

    /**
     * 查询所有的学生信息
     * @return
     * @throws Exception
     */
    public List<StuInfo> selectAllStuInfo() throws Exception;

    public StuInfo selectStuInfoByName(String name) throws Exception;
    
}
