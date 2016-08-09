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
    # 매트릭의 기준 표
    # 각 매트릭의 기준 (최소치, 최대치)
    table = {
        'avg_stmt': [0, 7],
        'cpnt_len': [3, 250],
        'stmt_num': [0, 80],
        'd_optr': [0, 35],
        'd_oprd': [0, 50],
        'ocr_optr': [0, 140],
        'ocr_oprd': [0, 120],
        'cpnt_voca': [3, 75],
        # 'voca_size': [3, 75],
        'dcs_stmt': [0, 9],
        'strc_lv': [0, 7],
        'entry_ptr': [1, 1],
        'exit_pnt': [1, 1],
        'uncond_num': [0, 0],
        'cyclomatic': [0, 15],
    }

    file = models.ForeignKey(
        File,
        on_delete=models.CASCADE,
    )

    name = models.CharField(max_length=100)
    function_id = models.CharField(max_length=10)
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

    #기준에 맞는지 여부
    def check_metric(self, name):
        try:
            # 최소치 이상 일 경우
            print(eval('self.table[name][0] <= self.' + name))
            if eval('self.table[name][0] <= self.' + name):
                # 최대치 이하일 경우
                if eval('self.table[name][1] >= self.' + name):
                    return True
                # 최소치 이상 최대치 이상
                else:
                    return False
            # 최소치 이하일 경우
            else:
                return False
        except(KeyError):
            # Table에 없을 경우 True
            return True

    def check_all(self):
        arr = []
        for k, v in self.table.items():
            if not self.check_metric(k):
                arr.append(k)
        return arr



    def return_score(self, name):
        try:
            exec('value = self.' + name)
            # 최소치 이상 일 경우
            if self.table[name][0] <= value:
                # 최대치 이하일 경우
                if self.table[name][1] >= value:
                    return 100  # 100점
                # 최소치 이상 최대치 이상
                else:
                    # 2배를 넘지 않으면 점수 계산
                    if value - self.table[name][1] >= 0:
                        return 100 - ((value - self.table[name][1]) / self.table[name][1] * 100)
                    # 2배를 넘으면 0점
                    else:
                        return 0
            #최소치 이하일 경우
            else:
                # 0점
                return 0
        except(KeyError):
            # Table에 없을 경우 True
            return True


class ScoreCard(models.Model):
    function = models.ForeignKey(
        Function,
        on_delete=models.CASCADE,
    )

    def __str__(self):
        return self.name