package com.example.service.impl;

import com.example.entity.User;
import com.example.dao.UserMapper;
import com.example.service.UserService;
import com.example.util.LoggerUtil;
import com.example.util.SystemConstant;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * Description: 用户服务
 * Date: 2018-11-05
 */

@Service("userService")
@Transactional
public class UserServiceImpl implements UserService {

    private UserMapper userMapper;

    @Autowired
    public void setUserMapper(UserMapper userMapper) {
        this.userMapper = userMapper;
    }

    @Override
    public int register(User user) {
        return userMapper.insertUser(user);
    }

    @Override
    public int login(String account, String password) {
        User user = userMapper.selectUserByAccount(account);
        if (user.getAccount() == null) {
            LoggerUtil.log("账号" + account + "不存在");
            return SystemConstant.ACCOUNT_NOT_EXIST;
        }
        if (!password.equals(user.getPassword())) {
            LoggerUtil.log("密码不匹配");
            return SystemConstant.PASSWORD_NOT_MATCH;
        }
        return user.getUserId();
    }

    @Override
    public User getUserByAccount(String account) {
        return userMapper.selectUserByAccount(account);
    }


}
