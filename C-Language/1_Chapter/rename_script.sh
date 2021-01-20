min_num=3
max_num=9
i=$min_num
while [ $i -le $max_num ]; do
        echo "$i"
	mv "$i".c 0"$i".c
        i=$[i+1] # в зависимости от shell также подходит i=$(($i + 1)) или i=`expr $i + 1`
done
