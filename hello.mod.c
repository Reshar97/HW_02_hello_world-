#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x96848186, "scnprintf" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x4f8207c9, "__asan_report_store1_noabort" },
	{ 0xb784d0a7, "__asan_report_load1_noabort" },
	{ 0xfb578fc5, "memset" },
	{ 0xbaddd214, "param_ops_string" },
	{ 0xe894f8f4, "__asan_unregister_globals" },
	{ 0xdc3c46c1, "__asan_register_globals" },
	{ 0x9cf156fd, "module_layout" },
};

MODULE_INFO(depends, "");

