# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='File',
            fields=[
                ('id', models.AutoField(verbose_name='ID', primary_key=True, serialize=False, auto_created=True)),
                ('name', models.CharField(max_length=100)),
                ('path', models.CharField(max_length=255)),
                ('numberoffunctions', models.IntegerField(default=0)),
                ('complexity', models.IntegerField(default=0)),
                ('testability', models.IntegerField(default=0)),
                ('structureness', models.IntegerField(default=0)),
                ('maintainability', models.IntegerField(default=0)),
                ('understandability', models.IntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name='Function',
            fields=[
                ('id', models.AutoField(verbose_name='ID', primary_key=True, serialize=False, auto_created=True)),
                ('name', models.CharField(max_length=100)),
                ('d_optr', models.IntegerField(default=0)),
                ('d_oprd', models.IntegerField(default=0)),
                ('ocr_optr', models.IntegerField(default=0)),
                ('ocr_oprd', models.IntegerField(default=0)),
                ('cpnt_len', models.IntegerField(default=0)),
                ('cpnt_vol', models.IntegerField(default=0)),
                ('cpnt_voca', models.IntegerField(default=0)),
                ('prg_lv', models.IntegerField(default=0)),
                ('prg_dif', models.IntegerField(default=0)),
                ('cpnt_eff', models.IntegerField(default=0)),
                ('prg_time', models.IntegerField(default=0)),
                ('itg_con', models.IntegerField(default=0)),
                ('dlv_bug', models.IntegerField(default=0)),
                ('exit_pnt', models.IntegerField(default=0)),
                ('stmt_num', models.IntegerField(default=0)),
                ('strc_lv', models.IntegerField(default=0)),
                ('uncond_num', models.IntegerField(default=0)),
                ('goto_num', models.IntegerField(default=0)),
                ('dcs_stmt', models.IntegerField(default=0)),
                ('avg_stmt', models.IntegerField(default=0)),
                ('lang_scope', models.IntegerField(default=0)),
                ('param_num', models.IntegerField(default=0)),
                ('call_num', models.IntegerField(default=0)),
                ('callby_num', models.IntegerField(default=0)),
                ('cyclomatic', models.IntegerField(default=0)),
                ('entry_ptr', models.IntegerField(default=0)),
                ('file', models.ForeignKey(to='analyze.File')),
            ],
        ),
        migrations.CreateModel(
            name='ScoreCard',
            fields=[
                ('id', models.AutoField(verbose_name='ID', primary_key=True, serialize=False, auto_created=True)),
                ('function', models.ForeignKey(to='analyze.Function')),
            ],
        ),
    ]
