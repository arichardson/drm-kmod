.PATH:	${.CURDIR}/gplv2/src ${.CURDIR:H}/drivers/dma-buf/

.include "../kconfig.mk"

KMOD=	linuxkpi_gplv2

SRCS=	linux_kmod_gplv2.c	\
	linux_compat.c		\
	linux_i2c.c		\
	linux_interval_tree.c	\
	linux_irq.c		\
	linux_mtrr.c		\
	linux_notifier.c	\
	linux_rbtree.c		\
	linux_sort.c		\
	linux_sync_file.c

SRCS+=	dma-buf.c \
	dma-fence-array.c \
	dma-fence-chain.c \
	dma-fence.c \
	dma-resv.c

.if ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386" || ${MACHINE_CPUARCH} == "aarch64"
SRCS+=	opt_acpi.h
.endif

SRCS+=	bus_if.h		\
	device_if.h		\
	pci_if.h		\
	pci_iov_if.h		\
	vnode_if.h

CFLAGS+= -I${.CURDIR:H}/include
CFLAGS+= -I${.CURDIR}/dummy/include
CFLAGS+= -I${.CURDIR}/gplv2/include
CFLAGS+= -I${SYSDIR}/compat/linuxkpi/common/include
CFLAGS+= '-DKBUILD_MODNAME="${KMOD}"' -DLINUXKPI_VERSION=50000
CFLAGS+= ${KCONFIG:C/(.*)/-DCONFIG_\1/}
CFLAGS.gcc+= -Wno-cast-qual

.include <bsd.kmod.mk>
CWARNFLAGS+=	-Wno-pointer-arith

