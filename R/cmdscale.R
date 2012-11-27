require("tseries")
dst = read.matrix("../data/dist_mat/dist_mat_0.dat")
mds = cmdscale(dst, k=2)
plot(mds)
write.table(mds, file="../data/points/0.dat", row.names=FALSE, col.names=FALSE)

