package org.User;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class UserController {
    private final UserRepository userRepository;
    private final UserSecurity userSecurity;

    @Autowired
    public UserController(UserRepository userRepository, UserSecurity userSecurity) {
        this.userRepository = userRepository;
        this.userSecurity = userSecurity;
    }

    @GetMapping("/register")
    public String registerUser(Model model) {
        model.addAttribute("user", new User());
        return "register";
    }

    @PostMapping("/register")
    public String registerUser(@ModelAttribute User user, Model model) {
        if (userRepository.findByEmail(user.getEmail()) != null) {
            model.addAttribute("error", "Email already exists!");
            return "register";
        } else {
            String hashedPassword = userSecurity.hashPassword(user.getPassword());
            user.setPassword(hashedPassword);
            userRepository.save(user);
            return "index";
        }
    }

    @GetMapping("/login")
    public String login(Model model) {
        return "login";
    }

    @PostMapping("/login")
    public String login(@RequestParam String email, @RequestParam String password, Model model) {
        User user = userRepository.findByEmail(email);
        if (user != null && userSecurity.matches(password, user.getPassword())) {
            return "index";
        } else {
            model.addAttribute("error", "Zły email albo hasło");
            return "login";
        }
    }
}
