package com.mysms.dao;

import com.mysms.model.ScoreInfo;

import java.util.List;

public interface IScoreInfoDao {

    public int insertScoreInfo(ScoreInfo model) throws Exception;

    public int updateScoreInfo(ScoreInfo model) throws Exception;

    public int deleteScoreInfo(int id) throws Exception;

    public ScoreInfo selectScoreInfoById(int id) throws Exception;

    public List<ScoreInfo> selectAllScoreInfo() throws Exception;


}
