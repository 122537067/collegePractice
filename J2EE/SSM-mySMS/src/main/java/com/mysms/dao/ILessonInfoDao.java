package com.mysms.dao;

import com.mysms.model.LessonInfo;

import java.util.List;

public interface ILessonInfoDao {

    /**
     * 新增课程
     * @param
     * @return
     * @throws Exception
     */
    public int insertLessonInfo(LessonInfo model) throws Exception;

    /**
     * 修改课程
     * @param
     * @param
     * @return
     * @throws Exception
     */
    public int updateLessonInfo(LessonInfo model) throws Exception;

    /**
     * 刪除课程
     * @param id
     * @return
     * @throws Exception
     */
    public int deleteLessonInfo(int id) throws Exception;

    /**
     * 根据id查询课程信息
     * @param id
     * @return
     * @throws Exception
     */
    public LessonInfo selectLessonInfoById(int id) throws Exception;

    /**
     * 查询所有的课程信息
     * @return
     * @throws Exception
     */
    public List<LessonInfo> selectAllLessonInfo() throws Exception;

    public LessonInfo selectLessonInfoByName(String name) throws Exception;

}
