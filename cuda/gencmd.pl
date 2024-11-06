#!/usr/bin/perl

my $nloop = 16;
my $logbase = "log.GTX";

for(my $ni=128; $ni<524289; $ni = $ni*2){
    my $bin = "./run.x";
    my $ifile = "gen-plum/backup/data.inp.".sprintf("%06d",$ni);
    my $log = "/tmp/log.txt";
    my $cmd = "$bin $ifile $nloop |tee -a $log";
    print "\t".$cmd ."\n";
}

1;
