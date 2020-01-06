package com.mysms.web;

import com.mysms.iservice.ILessonInfoService;
import com.mysms.model.LessonInfo;
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
@RequestMapping("/lessoninfo")
public class LessonInfoController extends BaseController {

    @Autowired
    private ILessonInfoService service;

    @RequestMapping(value="/list",method=RequestMethod.GET)
    public String getlist(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"LessonSearch");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "lessoninfo/list";
    }

    @RequestMapping(value="/list",method=RequestMethod.POST)
    @ResponseBody
    public List<LessonInfo> list() throws Exception{
        return this.service.getAllLessonInfos();
    }

    @RequestMapping(value = "/add",method = RequestMethod.GET)
    public String getadd(HttpServletRequest request,HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"LessonAdd");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "lessoninfo/add";
    }

    @RequestMapping(value = "/add",method = RequestMethod.POST)
    @ResponseBody
    public String add(HttpServletRequest request){
        LessonInfo lesson = new LessonInfo();
        lesson.setCode(request.getParameter("Code"));
        lesson.setName(request.getParameter("Name"));
        try {
            this.service.insertLesson(lesson);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/delete",method = RequestMethod.POST)
    @ResponseBody
    public String delete(HttpServletRequest request){
        try {
            this.validPermission(request,"LessonDel");
            String id = request.getParameter("id");
            this.service.deleteLesson(Integer.parseInt(id));
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getedit",method = RequestMethod.GET)
    public String getEdit(HttpServletRequest request,HttpServletResponse response, Model model) throws Exception {
        try {
            this.validPermission(request,"LessonModify");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        LessonInfo lesson = this.service.getLessonById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectLesson",lesson);
        return "/lessoninfo/edit";
    }

    @RequestMapping(value = "/edit",method = RequestMethod.POST)
    @ResponseBody
    public String Edit(HttpServletRequest request){
        LessonInfo lesson = new LessonInfo();
        lesson.setId(Integer.parseInt(request.getParameter("Id")));
        lesson.setCode(request.getParameter("Code"));
        lesson.setName(request.getParameter("Name"));
        try {
            this.service.updateLesson(lesson);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getdetail",method = RequestMethod.GET)
    public String getDetail(HttpServletRequest request,Model model) throws Exception {
        LessonInfo lesson = this.service.getLessonById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectLesson",lesson);
        return "/lessoninfo/detail";
    }
}
