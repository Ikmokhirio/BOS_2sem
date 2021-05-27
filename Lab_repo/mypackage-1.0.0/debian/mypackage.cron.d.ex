#
# Regular cron jobs for the mypackage package
#
0 4	* * *	root	[ -x /usr/bin/mypackage_maintenance ] && /usr/bin/mypackage_maintenance
