require("tseries")

dst = read.matrix("../data/dist_mat/dist_mat_0.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/0.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_1.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/1.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_2.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/2.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_3.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/3.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_4.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/4.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_5.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/5.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_6.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/6.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_7.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/7.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_8.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/8.dat", row.names=FALSE, col.names=FALSE)

dst = read.matrix("../data/dist_mat/dist_mat_9.dat")
mds = cmdscale(dst, k=2)
#plot(mds)
write.table(mds, file="../data/points/9.dat", row.names=FALSE, col.names=FALSE)

