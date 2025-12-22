#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#define MAX_STRING_LEN 20

static char str_buf[MAX_STRING_LEN];

static unsigned int idx = 0;

static char ch_val = ' ';

void update_str_buf(void) {
  if (idx < MAX_STRING_LEN) {
    str_buf[idx++] = ch_val;
  }
}

static int param_idx_set(const char *val, const struct kernel_param *kp) {
  int new_idx;
  int result = kstrtouint(val, 10, &new_idx);
  if (!result && new_idx <= MAX_STRING_LEN)
    idx = new_idx;
  else
    pr_warn("Invalid index provided.\n");
  return result;
}

static int param_idx_get(char *buffer, const struct kernel_param *kp) {
  return scnprintf(buffer, PAGE_SIZE, "%u", idx);
}

static int param_ch_val_set(const char *val, const struct kernel_param *kp) {
  long temp;
  int result = kstrtol(val, 10, &temp);
  if (!result && temp >= 0 && temp <= 255) {
    ch_val = (char)temp;
    update_str_buf();
  }
  return result;
}

static int param_ch_val_get(char *buffer, const struct kernel_param *kp) {
  return scnprintf(buffer, PAGE_SIZE, "%c", ch_val);
}

static const struct kernel_param_ops param_idx_ops = {
    .set = param_idx_set,
    .get = param_idx_get,
};

static const struct kernel_param_ops param_ch_val_ops = {
    .set = param_ch_val_set,
    .get = param_ch_val_get,
};

module_param_cb(idx, &param_idx_ops, NULL, 0644);
MODULE_PARM_DESC(idx, "Current index for writing a character");

module_param_cb(ch_val, &param_ch_val_ops, NULL, 0644);
MODULE_PARM_DESC(ch_val, "Character code to be written at given index");

module_param_string(str_buf, str_buf, sizeof(str_buf), 0444);
MODULE_PARM_DESC(str_buf, "Read-only parameter showing constructed string");

static int __init hello_init(void) {
  memset(str_buf, 0, sizeof(str_buf));
  pr_info("%s: init\n", KBUILD_MODNAME);
  return 0;
}

static void __exit hello_exit(void) { pr_info("%s: exit\n", KBUILD_MODNAME); }

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anton Zubin");
MODULE_DESCRIPTION("Module that writes \"Hello, World\" using custom params");
