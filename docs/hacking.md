CyberBit Game Crew:
========

Versioning System:
========

version [A.B.C]:

A: With A, its major release, all old bug fixed, with new features added
   Both(UI & Logic). A whole new experience of game.

B: With B, extra features added.

C: With C, smaller bug fixes.

Working with Git:
========

1. You need to Fork the project. You can read about forking [here.](https://help.github.com/articles/fork-a-repo)
2. Clone your repo. (```$ git clone git@github.com:<username>/cyberbitgame.git```)

3. Add the remote. (```$ git remote add <remote_name> <remote_adress>```)
   
   ```$ git remote add upstream https://github.com/cyberbitgame/cyberbitgame.git```

> Branching:
> ========

> We have 2 Branches, 
>
> 1. master - Stable game release
> 
> 2. develop - developer branch

4. Switch to branch develop. (```$ git checkout develop```)

5. Create a new meaningful name of branch from branch develop, suppose 
   you are working on a issue or fixing any bug, related to screen resolution, 
   switch to it and work on your code.

   ```$ git checkout -b screen-reso-bugfix develop```

6. Work on your bug/issue/patch & Merge it with develop.

  ```
   $ git add <your-modified-files>
   
   $ git commit -m "meaningfull message, if you fixed the issue, mention issue#"
   
   $ git checkout develop  
   
   Switched to branch 'develop'  
   
   $ git merge --no-ff screen-reso-bugfix 
   
   Updating ea1b82a..05e9557  
   
   (Summary of changes)  
   
   $ git branch -d screen-reso-bugfix  
   
   Deleted branch screen-reso-bugfix (was 05e9557).  
   
   $ git push origin develop
   ```

7. Make a pull request to develop branch of cyberbitgame repo. [Pull request](https://help.github.com/articles/creating-a-pull-request)

Communication:
========

All the communication will be in English.

Be polite and have patience when using any medium for communication. 

Respect the time of others.

**There are no stupid questions, only stupid answer.** 

So feel free to ask your questions via Mailing list or IRC Chatroom.

Use GMT, whenever you need to introduce time. So that everyone convert it
according to his/her TimeZone. For EX: if your current timezone is GMT +2,
and the time at your place is 5 AM,  and you want to meetup at 9 AM. So, 
tell ** 7 AM GMT. **

Mailing list are the main source of communication.

* Mailing List: 
  CyberBit Genearl ML (cyberbitgame-general(at)googlegroups(dot)com)

  Every mail has a special Tag. Use the Tag in subject line of the mail, and 
 
  it will help others
 
  - Feature - To discuss about new feature.
  - Meta - Any game related talk.
  - Story - About the game story.
  - Doc - About the documentation.
  - SignUP - To join the project.
  
  For Developers, we have a separate mailing list, discuss about coding issue,
  bugs, and all coding related tasks.
 
  CyberBit Internals (cyberbitgame-internals(at)googlegroups(dot)com)
  
* IRC: Available on #cyberbitgame at irc.freenode.net

Coding Standards:
========

You can find the coding standards [here.](https://github.com/cyberbitgame/cyberbitgame/blob/develop/CODING_STANDARDS)

Testing:
========

ToDo List:
========

The todo list can be found [here.](https://github.com/cyberbitgame/cyberbitgame/blob/develop/docs/ToDo.txt)
The list is organised in a manner, that the open tasks are at the top, after
that high priority tasks are defined (They are assigned to particular author).
And in the end, the working/completed tasks are mentioned.

[] Opened Task (no one is working on it)

[!] High priority task

[x] Working/Completed Task (someone finished it or working on it)

Presentations:
========

List of presentation, so that everyone feel comfortable working on project.

Date & Time of presentation can be found in [presentation.md](https://github.com/cyberbitgame/cyberbitgame/blob/develop/docs/presentation.md) file.

Roadmap:
========

Roadmap for our project can be found [here.](https://github.com/cyberbitgame/cyberbitgame/blob/develop/docs/roadmap.md)

Authors:
========

Please mention your name here.
* Sarvsav Sharma (sarvsav(at)gmail(dot)com)
* Brandon Burton (izodn0(at)gmail(dot)com)
* Raoul Kalisvaart (Raoulkalisvaart(at)hotmail(dot)com)
* Thunar

Contributors:
========

Special Thanks To:
========

[**CruceGame Crew**](https://github.com/CruceGameDevel/CruceGame)

