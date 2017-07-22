Tóm tắt đề bài
	Cho một mảng N phần tử. tìm max của 
		(a[i]^a[i+1]^..^a[j]) + (a[i1]^a[i1+1]^..^a[a[j1]) 
	Nmax = 4*10^5


Tóm tắt lời giải
	Đầu tiên ta tìm R1[j] là max của (a[i]^a[i+1]^..^a[j])  ( i chạy từ 1 đến j )
		độ phức tạp cần thiết là O(nlogn)
	L2[j] là max ( R1[i] , i = 1..n )  ( 1 vòng for O(n)
	
	Sau đó ta tìm max ( L2[i1] + (a[i1]^a[i1+1]^..^a[a[j1]) ) ( j1 = i1..n )
	
	Việc cần làm bây giờ là tìm R1[j] = max( a[i]^a[i+1]^..^a[j], i = 1..j )
	còn với (a[i1]^a[i1+1]^..^a[a[j1]) ta chỉ việc làm ngược lại với j1 = i1..n

	Ta có thể tính R1 trong O(n^2) với 2 vòng for cho j và i đoạn xor thì ta dùng
	tính chất của phép xor ( a^b = c -> c^b = a , c^a = b ) để tính trong O(1)
	(tính trước mảng sum[i] = (a[1]^a[2]^..^a[j]) ) 
		=> (a[i]^a[i+1]^..^a[j]) = sum[j]^sum[i-1] 

	Để tính R1 trong O(nlogn) ta sử dụng tính cây Trie
	
	Trie : mỗi phần tử sum[i] thêm vào trie được chuyển về dạng nhị phân. cây trie
	sẽ quản lý phần tử theo từng bit đó
			
					root
				     0         1
     				   0   1     0    1
				 …  …  … … …  … …   … 

	để tìm phép XOR max của sum[j]^sum[i] ( j = 1..n ) ta chỉ cần đổi sum[j] sang 
	biến nhị phân . với mỗi bit để tổng xor được lớn nhất thì ta cần tìm bit ngược
	với nó ( 1 - biti ) và tất nhiên ta sẽ tìm từ phần nhị phân lớn nhất trước rồi	
	giảm dần ( nghĩa là 00110010 thì ta tìm theo thứ tự 0 -> 0 -> 1 -> 1 .. -> 0 )
	 