package com.mysms.web;

import com.mysms.iservice.ILessonInfoService;
import com.mysms.iservice.IScoreInfoService;
import com.mysms.iservice.IStuInfoService;
import com.mysms.model.ScoreInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@Controller
@RequestMapping("/scoreinfo")
public class ScoreInfoController extends BaseController{

    @Autowired
    private IScoreInfoService service;

    @RequestMapping(value="/list",method=RequestMethod.GET)
    public String getlist(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"ScoreSearch");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "scoreinfo/list";
    }

    @RequestMapping(value="/list",method=RequestMethod.POST)
    @ResponseBody
    public List<ScoreInfo> list() throws Exception{
        return this.service.getAllScoreInfos();
    }

    @RequestMapping(value = "/add",method = RequestMethod.GET)
    public String getadd(HttpServletRequest request,HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"ScoreAdd");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "scoreinfo/add";
    }

    @Autowired
    private IStuInfoService stuInfoService;

    @Autowired
    private ILessonInfoService lessonInfoService;

    @RequestMapping(value = "/add",method = RequestMethod.POST)
    @ResponseBody
    public String add(HttpServletRequest request){
        ScoreInfo score = new ScoreInfo();
        score.setStuName(request.getParameter("StuName"));
        score.setLessonName(request.getParameter("LessonName"));
        score.setScore(Double.parseDouble(request.getParameter("Score")));
        try {
            score.setStuId(this.stuInfoService.getStuByName(score.getStuName()).getId());
            score.setLessonId(this.lessonInfoService.getLessonByName(score.getLessonName()).getId());
            this.service.insertScore(score);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/delete",method = RequestMethod.POST)
    @ResponseBody
    public String delete(HttpServletRequest request){
        try {
            this.validPermission(request,"ScoreDel");
            String id = request.getParameter("id");
            this.service.deleteScore(Integer.parseInt(id));
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getedit",method = RequestMethod.GET)
    public String getEdit(HttpServletRequest request,HttpServletResponse response, Model model) throws Exception {
        try {
            this.validPermission(request,"ScoreModify");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        ScoreInfo score = this.service.getScoreById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectScore",score);
        return "/scoreinfo/edit";
    }

    @RequestMapping(value = "/edit",method = RequestMethod.POST)
    @ResponseBody
    public String Edit(HttpServletRequest request){
        ScoreInfo score = new ScoreInfo();
        score.setId(Integer.parseInt(request.getParameter("Id")));
        score.setStuName(request.getParameter("StuName"));
        score.setLessonName(request.getParameter("LessonName"));
        score.setScore(Double.parseDouble(request.getParameter("Score")));
        try {
            score.setStuId(this.stuInfoService.getStuByName(score.getStuName()).getId());
            score.setLessonId(this.lessonInfoService.getLessonByName(score.getLessonName()).getId());
            this.service.updateScore(score);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getdetail",method = RequestMethod.GET)
    public String getDetail(HttpServletRequest request,Model model) throws Exception {
        ScoreInfo score = this.service.getScoreById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectScore",score);
        return "/scoreinfo/detail";
    }
}
