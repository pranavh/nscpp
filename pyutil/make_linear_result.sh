#! /usr/bin/bash

if [ $# == 0 ]; then
    echo "Usage: bash make_linear_result.sh <wdir> <case_name> <video_file> <plotstyle>"
    exit
fi

WDIR="$1"
CNAME="$2"
OUTFILE="$3"
PLTSTYLE="$4"

FRAMERATE=24

mkdir $WDIR/imgs

python3 make_linear_result.py $WDIR ${CNAME}_xvals.dat ${CNAME}_uvals.dat $PLTSTYLE "imgs/img{:04d}.png"

cd $WDIR

if [ -f $OUTFILE.mp4 ]; then
    rm $OUTFILE.mp4
fi

if [ -f imgs/img0000.png ]; then
    ffmpeg -r $FRAMERATE -i imgs/img%04d.png -vcodec libx264 -crf 25 $OUTFILE.mp4
    # # -f image2 -s 1920x1080 -pix_fmt yuv420p
else
    echo "No images were created in $WDIR/imgs. Video could not be made"
fi

cd -

rm -r $WDIR/imgs
