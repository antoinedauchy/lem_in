# lem_in (run on IOS)

To compile all the project, run Make in lem_in/lemin

Usage : ./lem-in < [antfarm] | ./lemin_viewer/lemin_viewer

![alt text](https://github.com/antoinedauchy/lem_in/blob/master/ScreenShot%20lem_in.gif)

# ant farm format
[antfarm] is a file whith the following format:

number_of_ants

the_rooms

the_links 

You can find some [antfarm] files in lem_in/lemin/maps

# the result
The quickest way to get n ants across the farm is displayed on the standard output,

in a specific format. (each move of each ant is written until all of them are arrived)

# lemin_viewer
lemin_view is a viewer that allow you too see ants going from one point to another of the antfarm,

after being choosen by the program ./lem-in

It uses the standard output of ./lem-in to create a graphic view.
