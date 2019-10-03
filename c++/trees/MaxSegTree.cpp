long long max_seg[4 * N];
long long max_combine(long long &a, long long &b) {
	return max(a , b);
}
void max_update(long long t, long long i, long long j) {
	if (i == j) {
		max_seg[t] = a[i];
		return ;
	}
	long long mid = (i + j) / 2;
	max_update(t * 2, i, mid);
	max_update(t * 2 + 1, mid + 1, j);
	max_seg[t] = max_combine(max_seg[2*t], max_seg[2*t+1]);
}
void max_update(long long t, long long i, long long j, long long x, long long y) {
	if (i == j) {
		max_seg[t] = y;
		return ;
	}
	long long mid = (i + j) / 2;
	if(x <= mid)	
		max_update(t * 2, i, mid, x, y);
	else 
		max_update(t * 2 + 1, mid + 1, j, x, y);
	max_seg[t] = max_combine(max_seg[2*t], max_seg[2*t+1]);
}
long long max_query(long long t, long long i, long long j, long long l, long long r) {
	if (l <=i && j <= r) {
		return max_seg[t];
	}
	long long mid = (i + j) / 2;
	if (l <= mid) {
		if (r <= mid) {
			return max_query(t * 2, i, mid, l, r);
		}
		else {
			long long a = max_query(t * 2, i, mid, l, r);
			long long b = max_query(t * 2 + 1,  mid + 1, j, l, r);
			return max_combine(a, b);
		}
	}
	else {
		return max_query(t * 2 + 1,  mid + 1, j, l, r);
	}
}