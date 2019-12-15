Keeping in mind that 

```
$ ascii
Usage: ascii [-adxohv] [-t] [char-alias...]
   -t = one-line output  -a = vertical format
   -d = Decimal table  -o = octal table  -x = hex table  -b binary table
   -h = This help screen -v = version information
Prints all aliases of an ASCII character. Args may be chars, C \-escapes,
English names, ^-escapes, ASCII mnemonics, or numerics in decimal/octal/hex.

Dec Hex    Dec Hex    Dec Hex  Dec Hex  Dec Hex  Dec Hex   Dec Hex   Dec Hex
  0 00 NUL  16 10 DLE  32 20    48 30 0  64 40 @  80 50 P   96 60 `  112 70 p
  1 01 SOH  17 11 DC1  33 21 !  49 31 1  65 41 A  81 51 Q   97 61 a  113 71 q
  2 02 STX  18 12 DC2  34 22 "  50 32 2  66 42 B  82 52 R   98 62 b  114 72 r
  3 03 ETX  19 13 DC3  35 23 #  51 33 3  67 43 C  83 53 S   99 63 c  115 73 s
  4 04 EOT  20 14 DC4  36 24 $  52 34 4  68 44 D  84 54 T  100 64 d  116 74 t
  5 05 ENQ  21 15 NAK  37 25 %  53 35 5  69 45 E  85 55 U  101 65 e  117 75 u
  6 06 ACK  22 16 SYN  38 26 &  54 36 6  70 46 F  86 56 V  102 66 f  118 76 v
  7 07 BEL  23 17 ETB  39 27 '  55 37 7  71 47 G  87 57 W  103 67 g  119 77 w
  8 08 BS   24 18 CAN  40 28 (  56 38 8  72 48 H  88 58 X  104 68 h  120 78 x
  9 09 HT   25 19 EM   41 29 )  57 39 9  73 49 I  89 59 Y  105 69 i  121 79 y
 10 0A LF   26 1A SUB  42 2A *  58 3A :  74 4A J  90 5A Z  106 6A j  122 7A z
 11 0B VT   27 1B ESC  43 2B +  59 3B ;  75 4B K  91 5B [  107 6B k  123 7B {
 12 0C FF   28 1C FS   44 2C ,  60 3C <  76 4C L  92 5C \  108 6C l  124 7C |
 13 0D CR   29 1D GS   45 2D -  61 3D =  77 4D M  93 5D ]  109 6D m  125 7D }
 14 0E SO   30 1E RS   46 2E .  62 3E >  78 4E N  94 5E ^  110 6E n  126 7E ~
 15 0F SI   31 1F US   47 2F /  63 3F ?  79 4F O  95 5F _  111 6F o  127 7F DEL

```


, think about how `sort`ing differs in numerical versus character. For example, `/usr/src/kernel-headers-5.3.15_1` and `/usr/src/kernel-headers-5.3.8_1` both sit on my system (for some reason) and contain things like 

```
/usr/src/kernel-headers-5.3.15_1$ ls include/uapi/linux/
a.out.h            bfs_fs.h          dlm_device.h          genwqe           if_packet.h          joystick.h           mount.h             nfsacl.h           ptrace.h           serial_reg.h        tipc_config.h        virtio_config.h
acct.h             binfmts.h         dlm_netlink.h         gfs2_ondisk.h    if_phonet.h          kcm.h                mpls.h              nfsd               qemu_fw_cfg.h      serio.h             tipc_netlink.h       virtio_console.h
adb.h              blkpg.h           dlm_plock.h           gigaset_dev.h    if_plip.h            kcmp.h               mpls_iptunnel.h     nilfs2_api.h       qnx4_fs.h          shm.h               tipc_sockets_diag.h  virtio_crypto.h
adfs_fs.h          blktrace_api.h    dlmconstants.h        gpio.h           if_ppp.h             kcov.h               mqueue.h            nilfs2_ondisk.h    qnxtypes.h         signal.h            tls.h                virtio_gpu.h
affs_hardblocks.h  blkzoned.h        dm-ioctl.h            gsmmux.h         if_pppol2tp.h        kd.h                 mroute.h            nl80211.h          qrtr.h             signalfd.h          toshiba.h            virtio_ids.h
agpgart.h          bpf.h             dm-log-userspace.h    gtp.h            if_pppox.h           kdev_t.h             mroute6.h           nsfs.h             quota.h            smc.h               tty.h                virtio_input.h
aio_abi.h          bpf_common.h      dma-buf.h             hash_info.h      if_slip.h            kernel-page-flags.h  msdos_fs.h          nubus.h            radeonfb.h         smc_diag.h          tty_flags.h          virtio_iommu.h
am437x-vpfe.h      bpf_perf_event.h  dn.h                  hdlc             if_team.h            kernel.h             msg.h               nvme_ioctl.h       raid               smiapp.h            types.h              virtio_mmio.h
android            bpfilter.h        dns_resolver.h        hdlc.h           if_tun.h             kernelcapi.h         mtio.h              nvram.h            random.h           snmp.h              udf_fs_i.h           virtio_net.h
apm_bios.h         bpqether.h        dqblk_xfs.h           hdlcdrv.h        if_tunnel.h          kexec.h              n_r3964.h           omap3isp.h         raw.h              sock_diag.h         udmabuf.h            virtio_pci.h
arcfb.h            bsg.h             dvb                   hdreg.h          if_vlan.h            keyboard.h           nbd-netlink.h       omapfb.h           rds.h              socket.h            udp.h                virtio_pmem.h
arm_sdei.h         bt-bmc.h          edd.h                 hid.h            if_x25.h             keyctl.h             nbd.h               oom.h              reboot.h           sockios.h           uhid.h               virtio_ring.h
aspeed-lpc-ctrl.h  btf.h             efs_fs_sb.h           hiddev.h         if_xdp.h             kfd_ioctl.h          ncsi.h              openvswitch.h      reiserfs_fs.h      sonet.h             uinput.h             virtio_rng.h
aspeed-p2a-ctrl.h  btrfs.h           elf-em.h              hidraw.h         ife.h                kvm.h                ndctl.h             packet_diag.h      reiserfs_xattr.h   sonypi.h            uio.h                virtio_scsi.h
atalk.h            btrfs_tree.h      elf-fdpic.h           hpet.h           igmp.h               kvm_para.h           neighbour.h         param.h            resource.h         sound.h             uleds.h              virtio_types.h
atm.h              byteorder         elf.h                 hsi              iio                  l2tp.h               net.h               parport.h          rfkill.h           soundcard.h         ultrasound.h         virtio_vsock.h
atm_eni.h          caif              elfcore.h             hsr_netlink.h    ila.h                libc-compat.h        net_dropmon.h       patchkey.h         rio_cm_cdev.h      spi                 un.h                 vm_sockets.h
atm_he.h           can               errno.h               hw_breakpoint.h  in.h                 lightnvm.h           net_namespace.h     pci.h              rio_mport_cdev.h   stat.h              unistd.h             vm_sockets_diag.h
atm_idt77105.h     can.h             errqueue.h            hyperv.h         in6.h                limits.h             net_tstamp.h        pci_regs.h         romfs_fs.h         stddef.h            unix_diag.h          vmcore.h
atm_nicstar.h      capability.h      erspan.h              hysdn_if.h       in_route.h           lirc.h               netconf.h           pcitest.h          rose.h             stm.h               usb                  vsockmon.h
atm_tcp.h          capi.h            ethtool.h             i2c-dev.h        inet_diag.h          llc.h                netdevice.h         perf_event.h       route.h            string.h            usbdevice_fs.h       vt.h
atm_zatm.h         cciss_defs.h      eventpoll.h           i2c.h            inotify.h            loop.h               netfilter           personality.h      rpmsg.h            sunrpc              usbip.h              vtpm_proxy.h
atmapi.h           cciss_ioctl.h     fadvise.h             i2o-dev.h        input-event-codes.h  lp.h                 netfilter.h         pfkeyv2.h          rseq.h             suspend_ioctls.h    userfaultfd.h        wait.h
atmarp.h           cdrom.h           falloc.h              i8k.h            input.h              lwtunnel.h           netfilter_arp       pg.h               rtc.h              swab.h              userio.h             watchdog.h
atmbr2684.h        cec-funcs.h       fanotify.h            icmp.h           io_uring.h           magic.h              netfilter_arp.h     phantom.h          rtnetlink.h        switchtec_ioctl.h   utime.h              wimax
atmclip.h          cec.h             fb.h                  icmpv6.h         ioctl.h              major.h              netfilter_bridge    phonet.h           rxrpc.h            sync_file.h         utsname.h            wimax.h
atmdev.h           cgroupstats.h     fcntl.h               if.h             iommu.h              map_to_7segment.h    netfilter_bridge.h  pkt_cls.h          scc.h              synclink.h          uuid.h               wireless.h
atmioc.h           chio.h            fd.h                  if_addr.h        ip.h                 matroxfb.h           netfilter_decnet.h  pkt_sched.h        sched              sysctl.h            uvcvideo.h           wmi.h
atmlec.h           cifs              fdreg.h               if_addrlabel.h   ip6_tunnel.h         max2175.h            netfilter_ipv4      pktcdvd.h          sched.h            sysinfo.h           v4l2-common.h        x25.h
atmmpc.h           cm4000_cs.h       fib_rules.h           if_alg.h         ip_vs.h              mdio.h               netfilter_ipv4.h    pmu.h              scif_ioctl.h       target_core_user.h  v4l2-controls.h      xattr.h
atmppp.h           cn_proc.h         fiemap.h              if_arcnet.h      ipc.h                media-bus-format.h   netfilter_ipv6      poll.h             screen_info.h      taskstats.h         v4l2-dv-timings.h    xdp_diag.h
atmsap.h           coda.h            filter.h              if_arp.h         ipmi.h               media.h              netfilter_ipv6.h    posix_acl.h        sctp.h             tc_act              v4l2-mediabus.h      xfrm.h
atmsvc.h           coff.h            firewire-cdev.h       if_bonding.h     ipmi_bmc.h           mei.h                netlink.h           posix_acl_xattr.h  sdla.h             tc_ematch           v4l2-subdev.h        xilinx-v4l2-controls.h
audit.h            connector.h       firewire-constants.h  if_bridge.h      ipmi_msgdefs.h       membarrier.h         netlink_diag.h      posix_types.h      seccomp.h          tcp.h               vbox_err.h           zorro.h
auto_dev-ioctl.h   const.h           fou.h                 if_cablemodem.h  ipsec.h              memfd.h              netrom.h            ppdev.h            securebits.h       tcp_metrics.h       vbox_vmmdev_types.h  zorro_ids.h
auto_fs.h          coresight-stm.h   fpga-dfl.h            if_eql.h         ipv6.h               mempolicy.h          nexthop.h           ppp-comp.h         sed-opal.h         tee.h               vboxguest.h
auto_fs4.h         cramfs_fs.h       fs.h                  if_ether.h       ipv6_route.h         meye.h               nfc.h               ppp-ioctl.h        seg6.h             termios.h           veth.h
auxvec.h           cryptouser.h      fsi.h                 if_fc.h          ipx.h                mic_common.h         nfs.h               ppp_defs.h         seg6_genl.h        thermal.h           vfio.h
ax25.h             cuda.h            fsl_hypervisor.h      if_fddi.h        irqnr.h              mic_ioctl.h          nfs2.h              pps.h              seg6_hmac.h        time.h              vfio_ccw.h
b1lli.h            cyclades.h        fsmap.h               if_frad.h        isdn                 mii.h                nfs3.h              pr.h               seg6_iptunnel.h    time_types.h        vhost.h
batadv_packet.h    cycx_cfm.h        fuse.h                if_hippi.h       iso_fs.h             minix_fs.h           nfs4.h              prctl.h            seg6_local.h       timerfd.h           vhost_types.h
batman_adv.h       dcbnl.h           futex.h               if_infiniband.h  isst_if.h            mman.h               nfs4_mount.h        psample.h          selinux_netlink.h  times.h             videodev2.h
baycom.h           dccp.h            gameport.h            if_link.h        ivtv.h               mmc                  nfs_fs.h            psci.h             sem.h              timex.h             virtio_9p.h
bcache.h           devlink.h         gen_stats.h           if_ltalk.h       ivtvfb.h             mmtimer.h            nfs_idmap.h         psp-sev.h          serial.h           tiocl.h             virtio_balloon.h
bcm933xx_hcs.h     dlm.h             genetlink.h           if_macsec.h      jffs2.h              module.h             nfs_mount.h         ptp_clock.h        serial_core.h      tipc.h              virtio_blk.h
```



. Which comes first, 5.3.15_1 or 5.3.8_1 ?     By a character sort, `0x38` = `8` comes after `0x31` = `1` in `0x31 0x35` = `15`.

However, numerical `sort -n` somehow knows that `15` in numbers is larger than `8`, yet smaller than `81` and `888`.
