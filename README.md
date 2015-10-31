-----------------------------------------------------------------
# COMP3004 

## Merged Log v0.011 9:34pm Oct 30th

- tested the persistance of projects (working), but found only the last project was shown (on first load)

- fixed display issue, (was adding to list OUTSIDE of for loop so only the last made was ever added to vector

- fixed crashing on exit, do not delete widget in control Class; use delete_later INSIDE ui class

- still need to rename dialogs (totally forgot)

----------------------------------------------------------------
## Merged Log v0.010 2:25am Oct 30th

- fixed flow and change of windows failure

- added true *shutdown* during window _reject_

- added persistance of projects and functions for saving ProfileEntity and Project 

- cleaned working directory a little

- minor memory fixes (doubtful that they work) most memory issues are from rapidxml

**TO DO Rename dialog windows to better represent actions (title) **

**Ready To Merge**

-----------------------------------------------------------------
## Merged Log v0.009 3:00am Oct 29th

- fixed some of the glitching windows when changing controllers

- implemented selective admin project display (based on which admin signs in)

- hopefully smoothened out the storage things, **NEED TO ADD PROJECT SAVING**

- project layout xml made, profile xml has new node <Admin> to dictate admin privilege when being made

- added a minor controller and starting window for the student view

**TO DO**
1. qualification form for the admin project maker 
2. reimplement the edit project button and stuff
3. determine what is making the windows lag and loose focus

_something I really don't want to do, but find a way to clean up the lost memory_

-----------------------------------------------------------------
## Merged Log v0.008

- Somewhat merged (or moreso adapted) wills admin stuff to the MasterControl and flow entities

- **NOTE:: DO NOT MESS WITH THE DELETES IN profileview AND adminview, THEY MAKE SURE IT ACTUALLY RENDERS WHEN MADE**

- memory foot-print is still a pain in the a&&

- most of the storage functions are done, except for anything connected to projects themselves

- **TODO** 3 versions of the descriptions of the qualifications

-----------------------------------------------------------------
## Merged Log v0.007

Branch Author | version style
------------- | -------------
Bill	      | v**B**_0.00x_
Joe           | v**J**_0.00x_
Will          | v**W**_0.00x_

------------------------------------------------------------------
### Iteration vB0.007 5:24pm 27

- added second qual register page

- (may need to add saving, i forget if it works)

- list / slider works and is read to temp profile atleast...


-------------------------------------------------------------------
### Iteration vB0.006 5:09am Oct 27th

- cleaned repo of uneeded Wizard files

- made qualification frame and have a (somewhat) working list on the register qualifications page
  _(mind, it doesn't do anything yet, but it displays a list of controllable qualification frames)_

- messed with the qualFrame stylesheet so that the QSlider didn't look like _ass_ though due to QT issues (bugs) the ticks 
  aren't there anymore

_The list was utter **BS** until I finally got it to work_
--------------------------------------------------------------------------------------------
### Iteration vW.006 2:53pm Oct 26th

-Made adminControl.

-login should be completed.



-------------------------------------------------------------------------------------------
### Iteration vB0.005 3:52am Oct 26th

- Had to revert to commit 5ad875c as *_Iteration v0.004_* was not clean (too many errors to build)

- Added XML Storage and a Control structure (LoginControl, MasterControl, StorageManager) to help direct flow of UI
  Data should be persisant so long as it is in the right directory

- Some minor issues in converting to new structures but most/all original register flows should be working

- A few extra files are in the commit, later versions will have them gone (wizards) as I experimented and went back to the
  original QWidget style

_**TODO::** make qualifications, **I NEED THEM** for storage structure and registration pages_

-------------------------------------------------------------------------------------------
### Iteration vW.005 1:53pm Oct 26th

=Added the ability to check for admin accounts when creating a new account

-Admins can be logged in now

-Fixes. Comments. Ugly code.

--------------------------------------------------------------------------------------------
### Iteration vJ0.001 2:10pm Oct 25th

-created RunPPID class

>>>>>>> COMP3004/master

--------------------------------------------------------------------------------------------
### Iteration vW0.004 2:10pm Oct 23rd

~~_Evil hitler looks for his next victim. Having commented small portions of the code, he hungrily looks for the next bit of work to pretend to do, and then claim credit for it. No one is safe from his gaze_~~

~~-Added ViewProfile Window.~~


---------------------------------------------------------------------------------------------------------
### Iteration vB0.003  5:06am Oct 23rd
- Changing windows messed up the repositioning somehow, fixed now (though it may differ due to titlebar height and edge
  thickness)

- editQualifications is in its infancy, though it is linked to registration and login_control with a temperary username (in
  case of [later on] more than one user trying to register the same name at nearly the same time)

- modified some of (most) of the UI constructors to pass username due to going from register to editQual (incomplete profile 
  means incomplete registration) and editQual to register due to having the username from before and sending it back 

- file system is fixed after an annoying amount of time

_That should be everything so far... I'm off to bed_

----------------------------------------------------------------------------------------------------------
### Iteration vB0.002 12:32am Oct 23rd
- Can now drag a window around and upon "changing" windows (destroying and creating) the child/new window will be in about 
   the same location as the original

- layouts for the Login and the Register windows changed, now they flow with the resize (and don't look like garbage after)

----------------------------------------------------------------------------------------------------------
### Iteration vB0.001  6:09pm Oct 22nd
- _FYI username_list.txt is required to be in the debug directory (where the executable is) for the current iteration of 'Login' to work [change from empty to VALID if username is in the list, otherwise WRONG]_

- also changed the line edit to have placeholder text (light grey) as opposed to set text
