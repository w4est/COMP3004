# Will's Branch Log
## COMP3004 

--------------------------------------------------------------------------------------------
### Iteration vW.005 1:53pm Oct 26th

=Added the ability to check for admin accounts when creating a new account

-Admins can be logged in now

-Fixes. Comments. Ugly code.

--------------------------------------------------------------------------------------------
### Iteration v0.004 2:10pm Oct 23rd

_Evil hitler looks for his next victim. Having commented small portions of the code, he hungrily looks for the next bit of work to pretend to do, and then claim credit for it. No one is safe from his gaze_

-Added ViewProfile Window.




---------------------------------------------------------------------------------------------------------
### Iteration v0.003  5:06am Oct 23rd
- Changing windows messed up the repositioning somehow, fixed now (though it may differ due to titlebar height and edge
  thickness)

- editQualifications is in its infancy, though it is linked to registration and login_control with a temperary username (in
  case of [later on] more than one user trying to register the same name at nearly the same time)

- modified some of (most) of the UI constructors to pass username due to going from register to editQual (incomplete profile 
  means incomplete registration) and editQual to register due to having the username from before and sending it back 

- file system is fixed after an annoying amount of time

_That should be everything so far... I'm off to bed_

----------------------------------------------------------------------------------------------------------
### Iteration v0.002 12:32am Oct 23rd
- Can now drag a window around and upon "changing" windows (destroying and creating) the child/new window will be in about 
   the same location as the original

- layouts for the Login and the Register windows changed, now they flow with the resize (and don't look like garbage after)

----------------------------------------------------------------------------------------------------------
### Iteration v0.001  6:09pm Oct 22nd
- _FYI username_list.txt is required to be in the debug directory (where the executable is) for the current iteration of 'Login' to work [change from empty to VALID if username is in the list, otherwise WRONG]_

- also changed the line edit to have placeholder text (light grey) as opposed to set text
