from django.db import models

# Create your models here.

class Project(models.Model):
    name = models.CharField(max_length=100)

    def __str__(self):
        return self.name


class File(models.Model):
    project = models.ForeignKey(
        Project,
        on_delete=models.CASCADE,
    )
    name = models.CharField(max_length=100)
    path = models.CharField(max_length=255)
    numberoffunctions = models.IntegerField(default=0)
    complexity = models.IntegerField(default=0)
    testability = models.IntegerField(default=0)
    structureness = models.IntegerField(default=0)
    maintainability = models.IntegerField(default=0)
    understandability = models.IntegerField(default=0)

    def __str__(self):
        return self.name

class Function(models.Model):
    file = models.ForeignKey(
        File,
        on_delete=models.CASCADE,
    )
    name = models.CharField(max_length=100)
    d_optr = models.IntegerField(default=0)
    d_oprd = models.IntegerField(default=0)
    ocr_optr = models.IntegerField(default=0)
    ocr_oprd = models.IntegerField(default=0)
    cpnt_len = models.IntegerField(default=0)
    cpnt_vol = models.IntegerField(default=0)
    cpnt_voca = models.IntegerField(default=0)
    prg_lv = models.IntegerField(default=0)
    prg_dif = models.IntegerField(default=0)
    cpnt_eff = models.IntegerField(default=0)
    prg_time = models.IntegerField(default=0)
    itg_con = models.IntegerField(default=0)
    dlv_bug = models.IntegerField(default=0)
    exit_pnt = models.IntegerField(default=0)
    stmt_num = models.IntegerField(default=0)
    strc_lv = models.IntegerField(default=0)
    uncond_num = models.IntegerField(default=0)
    goto_num = models.IntegerField(default=0)
    dcs_stmt = models.IntegerField(default=0)
    avg_stmt = models.IntegerField(default=0)
    lang_scope = models.IntegerField(default=0)
    param_num = models.IntegerField(default=0)
    call_num = models.IntegerField(default=0)
    callby_num = models.IntegerField(default=0)
    cyclomatic = models.IntegerField(default=0)
    entry_ptr = models.IntegerField(default=0)

    def __str__(self):
        return self.name

    def new_score(self):
        s = ScoreCard(function=self)
        s.save()

class ScoreCard(models.Model):
    function = models.ForeignKey(
        Function,
        on_delete=models.CASCADE,
    )

    def __str__(self):
        return self.name