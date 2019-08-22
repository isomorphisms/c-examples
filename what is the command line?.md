In `/usr/local/bin`, `/bin`, `/sbin`, and perhaps `/opt` or `~/github` are a variety of programs somebody else has written that you can run.


For example `cut` is useful in data "science". [datascienceatthecommandline.com]  `<data_file_of_interest.csv cut -d, -f3` will pull out the third column. (Hopefully—watch out for those `"`!) Another program (`awk` or `expr`) can then sum the column — or maybe `r -pie 'as.numeric(stem(stdin()))'` (`littler`) will create a histogram for you. GNU parallel (pi.dk/3) does a lot of these things too.


Various of these tools are written in C by someone who thought about it long enough to get it right. Not that the program necessarily does what you _want_, but the way it parses and allocates memory is not horrible.


A few programs I mentioned above (`awk`, `littler`, and `parallel`) are more like meta-programs — they’re programs that write programs. See the awk book (archive.org).
